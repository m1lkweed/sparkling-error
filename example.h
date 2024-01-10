#ifndef EXAMPLE_H_
#define EXAMPLE_H_
[[gnu::error(
"[54D[01m[K[m[01m"
"Nesting of tagged blocks is forbidden"
"[m[J\n   11 | "
)]]void custom_error();

void custom_msg_nop(){}
#define TAGGED_NEST_ERROR(c) (/*[7G[K*/\
__builtin_choose_expr(/*[2F[7G[K*/\
!(c),/*[2F[7G[K*/\
custom_msg_nop,/*[2F[7G[K*/\
custom_error/*[2F[7G[K*/\
)(/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~pad~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/))//[F[7G[K[2F[8C[01;31mTAGGED_NEST_ERROR (__builtin_error("Nesting of tagged blocks is forbidden"))[m

#define typecmp(x, y) (_Generic(((typeof(x)*){}), typeof(y)*:1, default:0))
struct{int counter; int nest_check;}taggged_block_anti_nest = {};
#define tagged_block /*[7G[K*/\
if(1){/*[7G[K*/\
TAGGED_NEST_ERROR/*[G[K   21 | #define [01;36mTAGGED_NEST_ERROR[m (__builtin_error("Nesting of tagged blocks is forbidden"))[8m*/\
(typecmp(taggged_block_anti_nest.nest_check,\
float));}if(1)for(struct{int counter; float \
nest_check;}taggged_block_anti_nest = {};\
taggged_block_anti_nest.counter < 1;\
++taggged_block_anti_nest.counter)
#endif
