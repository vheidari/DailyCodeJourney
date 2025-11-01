## 16.0 [Simulation-Robotic] - Implement a Delta Robot Workflow in the Godot Engine

I would like to simulate a delta robot and its workflow in the `Godot Engine`. To implement this, we should design the model in `Blender` and rig it with bones. After that, we will import it into Godot and set up the entire scene.

### What Should We Implement in the Scene?

To complete the project in the scene, we should also model a `conveyor belt` in Blender and then import it into the Godot Engine. We will then set up our camera, the delta robot’s proper position, and the conveyor belt.

### How Does the Whole System Work?

On the conveyor belt, we need an object generator that is responsible for generating cube objects and spreading them along the conveyor belt. 

The conveyor belt will move them according to the positions of the camera and the delta robot. The camera will capture images and send them to OpenCV software, which works as a backend (Backend Vision Engien). 

The `OpenCV` backend will recognize the objects, their positions, and their colors, before sending this information to the delta robot's controller. This controller will assign tasks to each delta robot. 

I mention the controller because, in a real-world scenario, we might have more than one delta robot in a production line. The controller should distribute the workflow among them.

### How About Camera Setup (Camera Angle) or Limitations in the Real World?

We aim to implement this as a real system. In our implementation, we should consider how sensors, cameras, motor torque, enviorment illumination and light, and conveyor belt speed function, as well as our limitations and how we could model them in the Godot Engine. 

With these considerations, we can identify bottlenecks in our real production.


