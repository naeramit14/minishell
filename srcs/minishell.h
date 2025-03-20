#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft.h"

typedef enum e_token_type
{
	CMD,
	READ_FILE,
	HERE_DOC,
	WRITE_FILE,
	APPEND_FILE,
	PIPE,
	ENV_VAR,
}	t_token_type;

typedef enum e_quote_state
{
	NORMAL,
	SINGLE_QUOTE,
	DOUBLE_QUOTE

}	t_quote_state;

typedef struct s_token
{
	t_token_type			token_type;
	char					*value;
	struct s_token			*next;

}	t_token;

typedef struct s_redirect
{
	t_token_type			token_type;
	char					*value;
	struct s_redirect		*next;

}	t_redirect;

typedef struct s_process
{
	char				**cmd;
	t_redirect			*redirect;
	int					*pipe_in;
	int					*pipe_out;
	int					*here_doc;
	pid_t				pid;
	struct s_process	*next;

}	t_process;

typedef struct s_redirect_store
{
	int	offset;
	int	infile_fd;
	int	outfile_fd;
	int	cur_infile_type;

}	t_redir_store;

#endif