# minishell

A simplified Bash-like shell written in C, using GNU Readline. Parses and runs
pipelines with redirections, heredocs and environment expansion, and implements
the core shell builtins. 1337 (42 Network) project.

## What it does

- **Interactive prompt** with history (`readline`/`add_history`).
- **Pipelines**: `cmd1 | cmd2 | ...`, arbitrary length.
- **Redirections**: `<`, `>`, `>>`, and here-documents (`<<`) with a delimiter,
  including quote-aware delimiter handling.
- **Quoting & expansion**: single/double quotes, `$VAR` and `$?` expansion,
  word splitting after expansion.
- **Builtins**: `cd`, `pwd`, `echo`, `env`, `export`, `unset`, `exit`.
- **External commands**: resolved against `PATH`, run via `fork`/`execve`.
- **Signals**: `Ctrl-C`, `Ctrl-\` and `Ctrl-D` handled to match Bash behavior
  (new prompt line, ignored in the shell, exit on empty input).
- **Exit status** (`$?`) tracked across builtins and external commands.

## How it works

```
readline -> clean_input (trim + spread_tokens)
         -> lexer   (raw string -> list of t_command, each with its own token list)
         -> parser  (syntax validation, expansion, redirection/heredoc collection)
         -> executer (forks per command, wires pipes/redirections, runs builtins in-process)
```

- `src/lexer/` turns the raw input line into tokens (words, `|`, `<`, `>`, `>>`,
  `<<` + their file/delimiter) and groups them into one `t_command` node per
  pipeline stage.
- `src/parser/` (`parser.c`, `expander.c`, `parse_errors.c`) checks the token
  list for syntax errors, expands variables and quotes, and collects the
  redirection files and heredoc delimiters.
- `src/executer/` (`executer.c`, `set_redirections.c`, `set_heredocs.c`,
  `get_path.c`) sets up pipes and file descriptors, resolves the binary path,
  and forks one child per command in the pipeline; a builtin run alone (no
  pipe) executes directly in the shell process so `cd`/`export`/`exit` affect
  the shell's own state.
- `src/builtins/` implements each builtin against a linked-list environment
  (`t_env`) kept in sync with `envp`.

## My part

Built with M'Hammed Boukelalen. I worked on the parser, expander, executer,
heredocs, redirections and builtins (`main.c`, `parser.c`, `expander.c`,
`executer.c`, `set_heredocs.c`, `set_redirections.c`, `get_path.c`,
`src/builtins/`).

## Build & run

```sh
make            # builds libft, then ./minishell (cc -Wall -Wextra -Werror, links -lreadline)
make start      # clears the screen and runs ./minishell
./minishell
```

## What I learned

- Writing a token-list parser with syntax error checks, rather than a
  recursive-descent design.
- Process orchestration for pipelines: creating N pipes, duplicating file
  descriptors per child, and avoiding fd leaks/deadlocks.
- Handling heredocs correctly under signals (Ctrl-C during heredoc input).
- The difference between builtins that must run in the parent shell (`cd`,
  `export`, `exit`, `unset`) versus in a forked child.
