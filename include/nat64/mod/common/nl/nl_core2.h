#ifndef __NL_CORE2_H__
#define __NL_CORE2_H__

#include <net/netlink.h>
#include <net/genetlink.h>
#include "nat64/common/config.h"
#include "nat64/common/genetlink.h"

size_t nl_core_data_max_size(void);
int nl_core_new_core_buffer(struct nl_core_buffer **out_buffer, size_t size);
void nl_core_free_buffer(struct nl_core_buffer *buffer);
bool nl_core_write_to_buffer(struct nl_core_buffer *buffer, void *data, size_t data_length);
int nl_core_send_buffer(struct genl_info *info, enum config_mode command, struct nl_core_buffer *buffer);
int nl_core_respond_error(struct genl_info *info, enum config_mode command, int error_code);
int nlcore_respond_struct(struct genl_info *info, enum config_mode command,
		void *content, size_t content_len);
int nl_core_send_ack(struct genl_info *info, enum config_mode command);
int nlcore_respond(struct genl_info *info, enum config_mode command, int error);
void nl_core_set_main_callback(int (*cb)(struct sk_buff *skb_in, struct genl_info *info));
int nl_core_send_multicast_message(struct nl_core_buffer * buffer);
int nl_core_init(void);
void nl_core_destroy(void);

#endif
