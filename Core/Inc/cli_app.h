#ifndef _CLI_APP_H_
#define _CLI_APP_H_

/*! CPP guard */
#ifdef __cplusplus
extern "C" {
#endif

#include "cli.h"

static cli_status_t help_func(cli_t cli, int argc, char **argv);
static cli_status_t blink_func(cli_t cli, int argc, char **argv);

#ifdef __cplusplus
}
#endif /* End of CPP guard */

#endif /* CLI_H_ */
