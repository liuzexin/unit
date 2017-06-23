
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Valentin V. Bartenev
 * Copyright (C) NGINX, Inc.
 */

#ifndef _NXT_CONF_INCLUDED_
#define _NXT_CONF_INCLUDED_


typedef struct nxt_conf_json_value_s  nxt_conf_json_value_t;
typedef struct nxt_conf_json_op_s     nxt_conf_json_op_t;


typedef struct {
    uint32_t  level;
    uint8_t   more_space;  /* 1 bit. */
} nxt_conf_json_pretty_t;


nxt_conf_json_value_t *nxt_conf_json_get_value(nxt_conf_json_value_t *value,
    nxt_str_t *path);
nxt_conf_json_value_t *nxt_conf_json_object_get_member(
    nxt_conf_json_value_t *value, nxt_str_t *name, uint32_t *index);

nxt_int_t nxt_conf_json_op_compile(nxt_mp_t *mp, nxt_conf_json_op_t **ops,
    nxt_conf_json_value_t *root, nxt_str_t *path,
    nxt_conf_json_value_t *value);
nxt_conf_json_value_t *nxt_conf_json_clone_value(nxt_mp_t *mp,
    nxt_conf_json_op_t *op, nxt_conf_json_value_t *value);

nxt_conf_json_value_t *nxt_conf_json_parse(nxt_mp_t *mp, u_char *start,
    u_char *end);

#define nxt_conf_json_str_parse(mp, str)                                      \
    nxt_conf_json_parse(mp, (str)->start, (str)->start + (str)->length)

uintptr_t nxt_conf_json_print_value(u_char *p, nxt_conf_json_value_t *value,
    nxt_conf_json_pretty_t *pretty);


#endif /* _NXT_CONF_INCLUDED_ */
