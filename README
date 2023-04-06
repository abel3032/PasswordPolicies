# PasswordPolicies

This program checks if a given series of password complies to the rules of the user. The policies are:
-length: the restriction can specify the minimum length or the minimum and maximum length of a password
-class: the restriction specifies how many different character classes the password must have at least; classes are: lowercase, uppercase, digit, and other characters
-must include: the password must include at least one character of the specified class  
-must not include: the password must NOT include any characters from that class.
-repetition: the restriction imposes how many times the same character can be repeated consecutively in the password
-consecutive: the restriction imposes a maximum number of consecutive characters (eg: abc or 123)

On the first line there is an unknown positive integer n, representing the number of rules to follow. On the next n lines there is a rule, in the following possible formats:

length <min_length> - the password must have min_length characters (inclusive); 0 < min_length
length <min_length> <max_length> - the password must have between min_length and max_length characters (inclusive); 0 < min_length <= max_length
class <min_class_count> - the password must have at least min_class_count different types of characters (lowercase letters, uppercase letters, numbers and other characters); 0 < min_class_count < 5
include <class> - the password must include at least one character from the specified class; class can be a, A, 0 or $, characters denoting the desired class
ninclude <class> - the password must not include any character from the specified class; class follows the same rules as above
repetition <max_count> - the same character can be repeated in consecutive positions a maximum of max_count times; 0 < max_count
consecutive <max_count> - password can have max_count consecutive characters in sequence; 0 < max_count
On the following lines, until EOF, there is one password per line, which will be checked with the specified rules.




