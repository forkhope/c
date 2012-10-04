#include "libhash.h"

/* The algorithm is a hash-search - the incoming name is converted into a
 * small non-negative integer, which is then used to index into an array of
 * pointers. An array element points to the beginning of a linked list of
 * blocks describling names that have that hash value. It is NULL if no
 * names have hashed to that value.
 * 程序中的hash表是一个指针数组,数组中的每一个指针指向一个链表,链表中每一个
 * 项(block)是一个结构体;当一个字符串(name)传进来时,程序调用hash()函数由该
 * 字符串得到一个较小的非负数,该非负数被作为hash表,即数组的下标使用,从而得到
 * 一个指向链表头的指针,然后再在该链表中查找(lookup())所给字符串是否存在.
 * The hashing function, which is used by both lookup and install, adds 
 * each character value in the string to a scrambled combination of the
 * previous ones and returns the remainder modulo the array size. 
 *
 * hash: form hash value for string s */
unsigned hash(const char *s)
{
	/* Unsigned arithemetic ensures that the hash value is non-negative */
	unsigned hashval;

	for (hashval = 0; *s != '\0'; ++s)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;	/* 求模,保证返回的值在数组下标范围内 */
}
