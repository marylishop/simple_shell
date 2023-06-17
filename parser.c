#include "shell.h"

/**
 * _parser_cmd - Parses a simple command from the prompt.
 * @myself: Name of the shell.
 * @cmd_line: Command line to be parsed.
 *
 * Return: Pointer to the command node or NULL.
 */
command_t *_parser_cmd(char *myself, char *cmd_line)
{
size_t i = 0;
char *cmd_str = NULL;
const char *arg_sep = " \n";
command_t *cmd_node = NULL;

cmd_str = strtok(cmd_line, arg_sep); /* Get the first token */
if (cmd_str)
{
cmd_node = new_cmd_node(myself);
add_tok_to_cmd(myself, cmd_node, i, cmd_str);

while (cmd_str != NULL)
{
cmd_str == NULL ? i : i++;
cmd_str = strtok(NULL, arg_sep);
if (cmd_str)
add_tok_to_cmd(myself, cmd_node, i, cmd_str);
}
}
return (cmd_node);
}
