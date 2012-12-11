#ifndef PING_TEST_H

#define PING_TEST_H

#include <stdint.h>

#define MIN_ADDR 1
#define MIN_CHAN MIN_ADDR
#define MAX_CHAN 14
#define MAX_ADDR 255
#define SND_BUFFER_SIZE     (100)
#define RCV_BUFFER_SIZE     (64)

/**
 * @brief Shows a helping text.
 * @param command the command name for which the help should be showed.
 */
void help(char * commandname);

/**
 * @brief Initializes a node for radio communication
 *
 * Initializes this node with a given radio address and on a given channel or
 * on a default channel, if no channel is given. A radio address must be given
 * in any case.
 *
 * @param arg
 */
void init(char * arg);

/**
 * @brief Pings another node.
 *
 * Sends out pings from this node to another node in a continuous manner, until
 * the stop command is used.
 */
void ping(char * arg);

uint16_t get_radio_address(void);

void set_radio_address(uint8_t addr);

void set_radio_channel(uint8_t chan);

void switch_to_rx(void);

/**
 * Stops any current pinging-action by this node and prints a summary of how
 * many pings got returned.
 * If the node was not pinging at the time of the method-call, this method does
 * nothing.
 *
 * @param arg
 */
void stop(char * arg);

void radio(void);

#endif /* PING_TEST_H */
