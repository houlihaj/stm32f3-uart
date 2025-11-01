#include "cli_app.h"
#include <string.h>  /* string handling functions (ex. strcmp and memset) */

// cmd_t cmd_tbl[] = {
//     {.cmd = "help", .func = help_func},
//     {.cmd = "blink", .func = blink_func}
// };

/**
  * @brief  Send Txt information message on UART Tx line (to PC Com port).
  * @note   To use in conjunction with cli.c library
  * @param  String String to be sent to user display
  * @retval None
  */
cli_status_t help_func(cli_t cli, int argc, char **argv)
{
	cli.println("HELP function executed");
	return CLI_OK;
}

/**
  * @brief  Send Txt information message on UART Tx line (to PC Com port).
  * @note   To use in conjunction with cli.c library
  * @param  String String to be sent to user display
  * @retval None
  */
cli_status_t blink_func(cli_t cli, int argc, char **argv)
{
	if(argc > 0) {
		if(strcmp(argv[1], "-help") == 0) {
			cli.println("BLINK help menu");
		} else {
			return CLI_E_INVALID_ARGS;
		}
	} else {
		cli.println("BLINK function executed");
	}
	return CLI_OK;
}
