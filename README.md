_This project has been created as part of the 42 curriculum by nhoussie, cmonmire_.

---

### Table of Contents

- [Description](#description)
- [Instructions](#instructions)
  - [Usage](#usage)
- [Resources](#resources)

---

## Description

This project is about creating a simple shell.

Just like a normal shell, this shell must handle prompt, working history, redirections, pipes, environment variables and signals. It must also implement a few built-in commands.

## Instructions

1. Build the program:

```
make
```

2. Execute the program:

```
./minishell
```

The program will then read your input just like a normal shell.

### Usage

Once started, you can use the program just like you would use a normal shell.

```sh
minishell$ echo "Hello world!"
```

The shell can handle input/output redirections:

- Input redirection:

```sh
minishell$ cat < infile
```

- Multi-line input redirection:

```sh
minishell$ cat << DELIMITER
> Hello world!
> DELIMITER
```

- Output redirection:

```sh
minishell$ echo "Hello world!" > output_file
```

- Output redirection (append mode):

```sh
minishell$ echo "Hello world!" >> output_file
```

The shell can handle pipes:

```sh
minishell$ ls | grep README
```

The shell provides access to environment variables:

```sh
minishell$ export KEY=value
minishell$ echo $KEY
value
minishell$ unset KEY
```

To exit the shell, you can use ctrl-D or the `exit` built-in command.

## Resources

For the parsing part of the project, [this article](https://github.com/kibatche/parser-bison) was used as a starting point for the parser's implementation.

For the execution part, the [Advanced Programming in the UNIX® Environment book](http://www.apuebook.com/) was very useful to discover and understand the new concepts introduced by the project.

AI was used during the final testing phase and as a last resort for little bugs.
