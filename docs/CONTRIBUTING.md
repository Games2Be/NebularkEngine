# Contributing Guide

Thank you for considering contributing to our project! We welcome contributions from everyone.

## Table of Contents
- [Getting Started](#getting-started)
- [Reporting Issues](#reporting-issues)
- [Making Changes](#making-changes)
  - [Code Standards](#code-standards)
  - [Commit Guidelines](#commit-guidelines)
- [Pull Request Process](#pull-request-process)
- [Community Guidelines](#community-guidelines)

## Getting Started

1. Fork the repository
2. Clone your fork locally:
   ```bash
   git clone https://github.com/your-username/repository.git
   ```
3. ```bash
   cd NebularkEngine
   git submodule update --init --recursive
   ```
4. Add premake5.exe to the root of your solution (eg. NebularkEngine/premake5.exe
5. ```bash
   GenerateProject.bat
   ```
6. Go to Nebulark/vendor/SDL/SDL3/build in file explorer and open the "SDL3.sln"
7. Right click and build the INSTALL (Don't worry about any errors)
8. In Nebulark/vendor/SDL/SDL3/build/Release copy the SDL3.dll to bin/Debug-windows-x86_64/Sandbox
9. Open the main solution "Nebulark.sln"
10. Right click Sandbox and "Set as startup project"
11. And run the project on Debug and x64
   

## Reporting Issues

When opening an issue, please include:
  - Description: Clear explanation of the problem
  - Expected vs Actual Behaviour
  - Environment:
    - Window
    - Mac
    - Linux
## Making changes
### Workflow
  1. Create a new branc:
     ```bash
     git checkout -b type/description(eg. graphics/rendering-pipeline)
     ```
     Branch type prefixes:
     - `feat/ `: New features
     - `fix/ `: Bug fixes
     - `docs/ `: Documentation
     - `chore/ `: Maintanance tasks
  2. Make your changes following our standards
  3. Commit your changes:
      ```bash
      git commit -m "type: descripion"
      ```
### Code standards
 - Follow existing style and patterns
 - Use clear, descriptive names
 - Comment complex logic
 - Keep lines under 100 characters
 - Include relevant tests

### Commit Guidelines

Use [Conventional](https://www.conventionalcommits.org/en/v1.0.0/) format:
  ```bash
  type(scope): description
  
  [optional body]
  
  [optional footer]
  ```

Common types:
  - `feat`: New feature
  - `fix`: Bug fix
  - `docs`: Documentation changes
  - `style`: Code formatting
  - `refactor`: Code restructuring
  - `test`: Test related
  - `chore`: Maintenance tasks

### Pull Request Process

1. Push yyour changes:
   ```bash
   git push origin branch-name
   ```
2. Open a PR against the `main` branch
3. Ensure PR includes:
   - Description of changes
   - Screenshots (if UI related)
   - Related issue number 
4. Address review comments promptly
5. maintainers will merge after approval

## Community Guidelines

- Be respectful and inclusive
- Assume good intentions
- Keep discussions contructive
- Follow our [Code of Conduct](CODE_OF_CONDUCT.md)
