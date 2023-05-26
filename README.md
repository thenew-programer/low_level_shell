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
You can configure your prompt by going to [cmdPrompt](./src/cmdPrompt.c) file and changing `prompt` variable.

## Builtin Commands

we only have two builtin commands
- **exit**
- **env**

## Special Characters
In the future we gonna add support to special characters

### note
`I'm not sure about the windows users if they can or not, probably it won't work, we have syscalls and I'm sure they are different in windows and linux`
<br>
`I hate windows, that's why I'm not gonna build one that supports windows`
<br>
`Linux is FREE if you don't value your time`
<br>
`I use arch by the way`
