#include <stdlib.h>
#include "cut.h"
#include "dll.h"
#include "token.h"
#include "parser.h"

static t_dll	*tokens_from_array(t_token_type *token_types, size_t size);

static void		free_token(void *token);

static void		test_parse_tokens(void);

static void		test_parse_tokens_valid(t_token_type *token_types, size_t size,
					const char *test);

static void		test_parse_tokens_invalid(t_token_type *token_types, size_t size,
					t_token_type error_token_type, const char *test);

int	main(void)
{
	test_parse_tokens();
	return (0);
}

static t_dll	*tokens_from_array(t_token_type *token_types, size_t size)
{
	t_dll	*tokens;
	t_token	*token;
	size_t	i;

	tokens = NULL;
	i = 0;
	while (i < size)
	{
		token = malloc(sizeof(t_token));
		if (token == NULL)
			break ;
		token->type = token_types[i++];
		token->value = NULL;
		add_dll(&tokens, new_dll(token));
	}
	return (tokens);
}

static void		free_token(void *token)
{
	if (token != NULL)
	{
		free(((t_token *)token)->value);
		free(token);
	}
}

static void		test_parse_tokens(void)
{
	test_parse_tokens_valid((t_token_type[]){T_WORD, T_WORD}, 2, "parse_tokens (word tokens)");
	test_parse_tokens_valid((t_token_type[]){T_REDIR_IN, T_WORD}, 2, "parse_tokens (redir input token)");
	test_parse_tokens_valid((t_token_type[]){T_REDIR_OUT, T_WORD}, 2, "parse_tokens (redir output token)");
	test_parse_tokens_valid((t_token_type[]){T_REDIR_APPEND, T_WORD}, 2, "parse_tokens (redir append token)");
	test_parse_tokens_valid((t_token_type[]){T_HEREDOC, T_WORD}, 2, "parse_tokens (heredoc token)");
	test_parse_tokens_valid((t_token_type[]){T_WORD, T_WORD, T_PIPE, T_WORD, T_WORD}, 5, "parse_tokens (words separed by pipe token)");
	test_parse_tokens_valid((t_token_type[]){T_REDIR_IN, T_WORD, T_WORD, T_REDIR_OUT, T_WORD, T_PIPE, T_HEREDOC, T_WORD, T_WORD, T_WORD, T_REDIR_OUT, T_WORD}, 12, "parse_tokens (multi-tokens (redirections, words and pipe)");
	test_parse_tokens_invalid((t_token_type[]){T_REDIR_IN}, 1, T_REDIR_IN, "parse_tokens (redir input token alone)");
	test_parse_tokens_invalid((t_token_type[]){T_REDIR_OUT}, 1, T_REDIR_OUT, "parse_tokens (redir output token alone)");
	test_parse_tokens_invalid((t_token_type[]){T_REDIR_APPEND}, 1, T_REDIR_APPEND, "parse_tokens (redir append token alone)");
	test_parse_tokens_invalid((t_token_type[]){T_HEREDOC}, 1, T_HEREDOC, "parse_tokens (heredoc token alone)");
	test_parse_tokens_invalid((t_token_type[]){T_PIPE}, 1, T_PIPE, "parse_tokens (pipe token alone)");
	test_parse_tokens_invalid((t_token_type[]){T_PIPE, T_WORD}, 2, T_PIPE, "parse_tokens (pipe as first token)");
	test_parse_tokens_invalid((t_token_type[]){T_WORD, T_PIPE}, 2, T_PIPE, "parse_tokens (pipe as last token)");
	test_parse_tokens_invalid((t_token_type[]){T_HEREDOC, T_PIPE, T_WORD}, 3, T_PIPE, "parse_tokens (pipe token before complete command)");
	test_parse_tokens_invalid((t_token_type[]){T_WORD, T_PIPE, T_PIPE, T_WORD}, 4, T_PIPE, "parse_tokens (double pipe token)");
	test_parse_tokens_invalid((t_token_type[]){T_REDIR_IN, T_REDIR_IN, T_WORD}, 3, T_REDIR_IN, "parse_tokens (double redir input token)");
	test_parse_tokens_invalid((t_token_type[]){T_REDIR_OUT, T_REDIR_OUT, T_WORD}, 3, T_REDIR_OUT, "parse_tokens (double redir output token)");
	test_parse_tokens_invalid((t_token_type[]){T_REDIR_APPEND, T_REDIR_APPEND, T_WORD}, 3, T_REDIR_APPEND, "parse_tokens (double redir append token)");
	test_parse_tokens_invalid((t_token_type[]){T_HEREDOC, T_HEREDOC, T_WORD}, 3, T_HEREDOC, "parse_tokens (double heredoc token)");
}

static void		test_parse_tokens_valid(t_token_type *token_types, size_t size,
					const char *test)
{
	t_unit_test	*unit_test;
	t_dll		*tokens;
	t_token		*token;

	unit_test = new_unit_test(test, false);
	tokens = tokens_from_array(token_types, size);
	cut_assert(tokens != NULL, unit_test, "token list initialization succeeds");
	token = parse_tokens(tokens);
	cut_expect(token == NULL, unit_test,
		"returns NULL pointer for valid list of tokens");
	clear_dll(&tokens, free_token);
	end_unit_test(unit_test);
}

static void		test_parse_tokens_invalid(t_token_type *token_types, size_t size,
					t_token_type error_token_type, const char *test)
{
	t_unit_test	*unit_test;
	t_dll		*tokens;
	t_token		*token;

	unit_test = new_unit_test(test, false);
	tokens = tokens_from_array(token_types, size);
	cut_assert(tokens != NULL, unit_test, "token list initialization succeeds");
	token = parse_tokens(tokens);
	cut_expect(token != NULL, unit_test,
		"returns non-null pointer to token for invalid list of tokens");
	cut_expect(token != NULL && token->type == error_token_type, unit_test,
		"returns pointer to the token that caused "
		"an error for invalid list of tokens");
	clear_dll(&tokens, free_token);
	end_unit_test(unit_test);
}
