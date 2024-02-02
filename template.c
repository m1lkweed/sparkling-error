// Create a single type of error
// "XX" should match the line number of ERROR_IF's __builtin_choose_expr
[[gnu::error(
"[54D[01m[K[m[01m"
"It's only cursed code if it compiles"
"[m[J\n   XX | "
)]]void custom_error();

// Create a single type of warning
// "XX" should match the line number of WARN_IF's __builtin_choose_expr
[[gnu::warning(
"[58D[01m[K[m[01m"
"Here's a custom warning"
"[m[J\n   XX | "
)]]void custom_warning();

void custom_msg_nop(){}

// Some terminals are picky about line length and line wrapping w.r.t. backspacing and cursor manipulation
// so to be safe, any lines we expect to manipulate except the last one are shortened.
// The pad sections control the length of the tilde bar underneath the error context
#define ERROR_IF(c) (/*[7G[K*/\
__builtin_choose_expr(/*[2F[7G[K*/\
!(c),/*[2F[7G[K*/\
custom_msg_nop,/*[2F[7G[K*/\
custom_error/*[2F[7G[K*/\
)(/*~~~~~~~~~~~~~pad~~~~~~~~~~~~~~*/))//[F[7G[K[2F[8C[01;31m[KOtherwise, it's just a sparkling error[m

#define WARN_IF(c) (/*[7G[K*/\
__builtin_choose_expr(/*[2F[7G[K*/\
!(c),/*[2F[7G[K*/\
custom_msg_nop,/*[2F[7G[K*/\
custom_warning/*[2F[7G[K*/\
)(/*~~~pad~~~~*/))//[F[7G[K[2F[8C[01;35m[KSoup is good food.[m

int main(void){
	WARN_IF(1);
	ERROR_IF(1);
}
