#include "shell.h"

/**
 * add_rvar_node - A variable to be add at the endof a r_var list.
 *@head: The head.
 *@lvar: The length (the variable).
 *@val: The value
 *@lval:The length (the value).
 *
 *Return: address of the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
r_var *new, *temp;

new = malloc(sizeof(r_var));
if (new == NULL)
return (NULL);

new->len_var = lvar;
new->val = val;
new->len_val = lval;

new->next = NULL;
temp = *head;

if (temp == NULL)
{
*head = new;
}
else
{
while (temp->next != NULL)
temp = temp->next;
temp->next = new;
}

return (*head);
}

/**
 *free_rvar_list - A rvar list TO BE FREE
 *@head: The head.
 *
 *Return: no return.
 */
void free_rvar_list(r_var **head)
{
r_var *temp;
r_var *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}
