*This project has been created as part of the 42 curriculum by beldemir, hbayram.*

# miniRT

## Description 
This project is about creating a 3D viewer using raytracing technique.

Basically the 'RT' technique works just like opposite of a human eye. In real life the light coming from sources hits objects and reflects to eye and that is how we see colors basically. And we'll be sending imaginary rays for each pixel on window and color them depending the object that ray hit and/or the lights around.

## Instructions

To try it out:

- Get your Linux computer.
- Download or pull the repository.
- Place the projects needed for the compilation to the inc/ folder.
    - Your libft as "_libft_" ([click for mine](https://github.com/berkeldemir/libft))
    - Your get_next_line as "_gnl_" ([click for mine](https://github.com/berkeldemir/get_next_line))
    - Minilibx library as "_mlx_" ([click for official 42Paris repo](https://github.com/42paris/minilibx-linux))
- In the root of the folder, type <code>make</code> command.
- All the necessary compilation will be automatically made by the command <code>make</code>.
- You can run the program with the <code>./minirt \<mapname\>.rt</code> command.

> If you experience any-type of error on compiling, you can change the libft and/or gnl with mine which provided above.

## Resources

During the development of this project, we relied on several classic references to understand the core concepts of ray tracing and 3D mathematics:
- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html) - The ultimate guide that helped shape the core logic of our raytracer.
- [Building a miniRT - 42 project part 1](https://medium.com/@iremoztimur/building-a-minirt-42-project-part-1-ae7a00aebdb9) by iremoztimur.
- [Ray Tracing YouTube Tutorial](https://www.youtube.com/watch?v=2BLRLuczykM) - A great visual resource for understanding the mathematical concepts.

**AI Usage**
Artificial Intelligence was used as a conceptual learning tool. We primarily used it to understand the mathematical explanations behind translating 3D objects into a 2D space, and to get suggestions for code optimization.

## Mathematic Behind It

Following the principles introduced in *Ray Tracing in One Weekend*, the engine of this project relies heavily on linear algebra and 3D vector mathematics. Here is a breakdown of how we translated those concepts into our C implementation:

### 1. The Camera and Coordinate System
To render a 3D scene, we first establish a virtual viewport in front of our camera. 
* **Orientation:** We use **Cross Products** between the camera's forward vector and the world's "up" vector to calculate the camera's precise local `right` and `up` vectors. This guarantees a mathematically sound right-handed coordinate system.
* **Viewport Scaling:** The horizontal Field of View (FOV) is converted into radians to calculate the physical height and width of the viewport, maintaining the exact aspect ratio of the window so objects do not stretch.

### 2. Ray Generation
For every single pixel on the 2D window (x, y), we generate an imaginary 3D laser (a `t_ray`). 
* We remap the window coordinates into a normalized `[-1, 1]` range.
* The ray's `origin` is set to the camera's coordinates, and its `direction` is calculated by adding the scaled `right` and `up` vectors to the camera's forward vector. The final direction vector is strictly normalized to a length of `1.0` to ensure accurate intersection math later on.

### 3. Intersection Testing (The Core Engine)
As the ray travels, we test if it hits any object by solving algebraic equations. If a ray hits multiple objects, we always record the closest valid hit distance (`t`).
* **Spheres:** We solve a quadratic equation ($at^2 + bt + c = 0$) using the Dot Product to find the discriminant ($\Delta$). If $\Delta > 0$, the ray hits the sphere.
* **Planes:** We use the Dot Product between the ray direction and the plane's normal. If the result is close to zero, the ray is parallel and misses. Otherwise, we calculate the exact distance $t$ where the intersection occurs.
* **Cylinders (The Complex Shape):** Instead of standard dot-product projection, our implementation uses **Lagrange's Identity** and **Cross Products** to elegantly solve the quadratic equation for an infinite cylinder. We then use scalar projections to slice this infinite tube into a finite `height`, and calculate separate plane-intersections to cap the top and bottom disks.

### 4. Surface Normals and Lighting
Once the closest hit is established, we calculate the exact 3D point of impact and its surface normal (the vector pointing perpendicular to the surface).
* **Inside-Out Check:** Using the Dot Product, we check if the camera ray is hitting the *inside* of an object. If so, we invert the normal vector by multiplying it by `-1` so the inner walls render correctly.
* **Shading & Shadows:** To calculate diffuse lighting, we take the Dot Product between the normalized light direction vector and the object's surface normal. If the angle is too steep or if a shadow ray detects another object blocking the light, the diffuse lighting is clamped to `0.0`. 
* Finally, ambient and diffuse ratios are multiplied by the object's base RGB values and safely bit-shifted into a single 32-bit integer for the MiniLibX image buffer.