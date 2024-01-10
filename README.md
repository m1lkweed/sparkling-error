# sparkling-error
 ![An example of an error generated with sparkling-error](/assets/sparkling_error.png)
 
 This should never be used — especially not in production buildlogs — but it still exists.
# Why?
The sane, correct ways of creating an error/warning all have annoying problems that this aims to solve:
* `#error`/`#pragma`/`_Pragma` can only be triggered or suppressed by preprocessor conditionals. This means that type-checking and other compile-time checks can't be performed.
* `_Static_assert` prepends its own additional message about a failed static assertion which, while correct, obscures the source of fault for the developer. Sparkling errors are designed to look natural.

I initially planned on using this to generate better diagnostics for metaprogramming (see [example.c](example.c)) but this could (and definitely shouldn't!) be used to quote sections of the C standard or your own documents when printing an explicitly-checked-for error.
# How?
These headers rely on GCC not sanitizing comments when giving context for diagnostic messages, and not sanitizing the input string for `gnu::error`/`gnu::warning` attributes. Other attributes and printed sections are sanitized, so sadly this is the only way to do this. Read [template.c](template.c) for more details on usage.

This works on all recent versions of GCC, but not on Clang.
