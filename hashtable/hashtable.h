#ifndef H_HASHTABLE
#define H_HASHTABLE

#define HASH_TABLE_SIZE 30

// Maybe try a struct for hashtable?

// All of these functions return -1 on error
int h_hash(char **key);
int h_add(char **key, char **value);
int h_exists(char **key);
int h_get(char **key);
int h_remove(char **key);

#endif
