# Unreal Engine 5 C++ Course Roadmap

Source: https://www.udemy.com/course/unrealcourse/

Course: Unreal Engine 5 C++ Game Development (Fully Updated in 5.6)

Status: Not started

## Course Snapshot

- Provider: Udemy / GameDev.tv Team and Kaan Alpar
- Public course version: Last updated 2026-06
- Scope: 6 sections, 194 lectures, about 26h 16m
- Outcome: Build four Unreal Engine 5.6 C++ games while learning Unreal gameplay systems, C++, Blueprints, input, UI, animation, AI, effects, and packaging.

## Progress Rules

- Mark checklist items only after the related project work is committed or otherwise verified.
- Add commit notes under the matching session's `Related commits` section.
- Keep notes factual and tied to observable work in the repository.
- Record builds, editor runs, packaging, or tests only when they were actually performed.

## Session 01 - Introduction & Setup

Status: Not started

Course section: Introduction & Setup, 13 lectures, about 1h 18m.

### Goals

- Prepare the Unreal Engine and C++ development environment.
- Learn editor navigation, actor placement, compiling, and the C++ versus Blueprint workflow.

### Checklist

- [ ] Confirm Unreal Engine 5.6 or the selected course-compatible engine version.
- [ ] Confirm compiler and IDE setup for this workstation.
- [ ] Create or validate the starter C++ project.
- [ ] Compile the fresh project from the IDE or Unreal build tools.
- [ ] Capture notes on C++ versus Blueprint responsibilities for this project.

### Related commits

None yet.

## Session 02 - Obstacle Assault

Status: Not started

Course section: Obstacle Assault, 34 lectures, about 4h 35m.

### Goals

- Build a platformer prototype focused on core C++ actor movement and gameplay logic.
- Practice variables, structs, functions, Tick, frame-rate independent movement, actor transforms, Blueprint child classes, level design, and packaging.

### Checklist

- [ ] Set up the Obstacle Assault project area and test level.
- [ ] Create the first C++ actor class for moving platforms.
- [ ] Add variables, structs, logging, and arithmetic practice in C++.
- [ ] Implement actor movement with `SetActorLocation`, `GetActorLocation`, `Tick`, velocity, and delta time.
- [ ] Refactor movement into functions and member functions.
- [ ] Add Blueprint child classes for configurable platform behavior.
- [ ] Detect travel distance and correct movement overshoot.
- [ ] Add rotating platform behavior.
- [ ] Import visual assets and build obstacle geometry.
- [ ] Tune player movement and physics for the level.
- [ ] Complete the Obstacle Assault level design pass.
- [ ] Package or otherwise validate a playable build.

### Related commits

None yet.

## Session 03 - Dungeon Escape

Status: Not started

Course section: Dungeon Escape, 50 lectures, about 6h 50m.

### Goals

- Build a first-person puzzle adventure using components, triggers, delegates, item pickup logic, locks, line traces, collision, input, and lighting.
- Practice C++ pointers, references, access control, arrays, casting, tags, constructors, and component communication.

### Checklist

- [ ] Create the Dungeon Escape project area and level.
- [ ] Set up lighting, materials, and first-person game mode.
- [ ] Implement a reusable mover actor component.
- [ ] Practice pointer access through component ownership and `GetOwner`.
- [ ] Move actors with `FMath::VInterpConstantTo` and return movement.
- [ ] Create trigger logic with a box component and constructor setup.
- [ ] Use `FindComponentByClass` to connect trigger and mover behavior.
- [ ] Bind overlap behavior with C++ delegates.
- [ ] Use tags and logical conditions to identify valid actors.
- [ ] Refactor trigger logic and add accessors for movement state.
- [ ] Track pressure plate actor counts.
- [ ] Build pressure plate Blueprint behavior.
- [ ] Create collectible items and apply tags in C++.
- [ ] Create lock actors with C++ subobjects and Blueprint setup.
- [ ] Configure collision and visibility changes for lock activation.
- [ ] Set up Enhanced Input assets and C++ input handling.
- [ ] Implement interaction tracing with line or shape traces.
- [ ] Use references and pass-by-reference in trace helpers.
- [ ] Add inventory behavior with `TArray`, item removal, and taking items back.
- [ ] Import dungeon assets and add lighting polish.
- [ ] Build secret wall and final escape puzzle.

### Related commits

None yet.

## Session 04 - Battle Blaster

Status: Not started

Course section: Battle Blaster, 46 lectures, about 5h 58m.

### Goals

- Build a tank battler with pawn classes, player input, turret aiming, enemy towers, projectiles, damage, level flow, UI, effects, and sound.
- Practice inheritance, forward declarations, local transforms, timers, spawning actors, damage delegates, game instance state, widgets, particles, and camera shake.

### Checklist

- [ ] Bring in or create the Battle Blaster starter project area.
- [ ] Create a base pawn class and tank child class.
- [ ] Add camera and spring arm setup.
- [ ] Create the C++ game mode.
- [ ] Configure Enhanced Input mapping for tank movement.
- [ ] Implement move input with input action values.
- [ ] Move and rotate the tank with local transform functions.
- [ ] Trace from the cursor and rotate the turret toward the hit point.
- [ ] Create enemy tower C++ and Blueprint classes.
- [ ] Query tower actors and rotate enemies toward the player.
- [ ] Add projectile spawn points and timer-driven firing.
- [ ] Spawn projectiles and use projectile movement.
- [ ] Handle hit events and actor ownership.
- [ ] Create a health component.
- [ ] Apply damage and respond to `OnTakeAnyDamage`.
- [ ] Implement pawn death for enemies and the player tank.
- [ ] Add game-over cursor behavior and restart flow.
- [ ] Create game instance level management.
- [ ] Add countdown and gameplay UI widgets.
- [ ] Spawn particle systems, play sounds, and add camera shake.
- [ ] Design the Battle Blaster levels.

### Related commits

None yet.

## Session 05 - Shooter Sam

Status: Not started

Course section: Shooter Sam, 50 lectures, about 7h 34m.

### Goals

- Build a third-person shooter with character animation, weapons, line-trace shooting, health, AI controllers, behavior trees, blackboards, services, tasks, HUD, sound, and level polish.
- Practice animation Blueprints, blend spaces, state machines, sockets, virtual functions, protected access, loops, behavior tree tasks, decorators, and services.

### Checklist

- [ ] Set up the Shooter Sam test level.
- [ ] Import Shooter Sam assets.
- [ ] Review and adapt the third-person template.
- [ ] Implement Vector2D movement input and mouse look behavior.
- [ ] Configure player camera and rotation settings.
- [ ] Create skeletal animation setup and animation Blueprint.
- [ ] Build blend spaces and connect movement speed and direction.
- [ ] Add animation state machines for grounded and airborne movement.
- [ ] Add additive aim animation behavior.
- [ ] Create crosshair HUD.
- [ ] Add shooting input.
- [ ] Create gun C++ and Blueprint classes.
- [ ] Spawn the gun and attach it to a character socket.
- [ ] Trace from the player viewpoint to simulate bullets.
- [ ] Add gun particle effects.
- [ ] Apply bullet damage.
- [ ] Implement character health and death animation behavior.
- [ ] Apply C++ inheritance concepts with overloads, macros, protected members, and virtual functions.
- [ ] Create AI controller focus and movement with NavMesh.
- [ ] Implement AI line of sight checks.
- [ ] Configure behavior trees and blackboards.
- [ ] Start behavior trees from C++.
- [ ] Set blackboard keys from C++.
- [ ] Use loops to manage AI patrol or decision data.
- [ ] Add behavior tree tasks, selectors, decorators, and services.
- [ ] Create custom C++ behavior tree tasks for movement or shooting.
- [ ] Add health bar HUD.
- [ ] Add sound cues.
- [ ] Build the final SciFi level and finishing touches.

### Related commits

None yet.

## Session 06 - Bonus And Wrap-Up

Status: Not started

Course section: Bonus: One Last Thing, 1 lecture, about 1m.

### Goals

- Close the course roadmap and record any final follow-up work.

### Checklist

- [ ] Review completed course projects.
- [ ] Record final notes, open gaps, and personal follow-up tasks.
- [ ] Confirm all completed work has matching commits or notes.

### Related commits

None yet.
