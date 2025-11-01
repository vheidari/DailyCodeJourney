## 2.0.[RTS]-SceneTransition-CommandosStyle on the Godot engine
We have a user player and two or more scenes. The user should go from scene one to scene two and so on.

### What is Scene One?
Scene one is a world environment where the player interacts and plays.

### What is Scene Two (or More)?
Scene two could be a pipe, a train, a house, or anything else.

---

### What Is This Like?
This is similar to the Commandos game, where the user moves from the world environment to a house. Each house should be a scene in the Godot engine. When the user interacts with a house's door and wants to enter, we should change the scene from the world to the house.

### Can the Player Go Through Multiple Scenes?
Yes, for example, if the user finds a pipe and enters it, then climbs a ladder, they will go to a basement. From the basement, they can go to a garage and then return to the world.

```

[world] → [pipe] → [basement] → [garage] → [world]

```

