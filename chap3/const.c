const float pi = 3.14159f;
const int lower_limit = 32;
const char greeting1[] = "Hello:\n";

// almost the same, the chars cannot be changed
// but the address inside greeting still can
const char *greeting2 = "Hello:\n";

// this is exactly the same as greeting1
const char * const greeting3 = "Hello:\n";

// also for parameters
enum Boolean string_match(const char str[], const char line[]);

