# Low Level Shell (LLC)
A simple shell built in C.
## Install

```
git clone https://github.com/low_level_shell
cd low_level_shell
make
./Bin/shell

```
#### To clean it up
```
make clear
```

## Configuration
You can configure your prompt by clicking on this [main](./src/main.c) file and changing the argument given to `readline` variable, in the `23th line`.

## Builtin Commands

we only have two builtin commands
- **cd :** change directory
- **env :** print environment variables
- **exit :** exit the low_level_shell

