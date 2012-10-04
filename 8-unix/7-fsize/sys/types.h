#ifndef L_TYPES_H
#define L_TYPES_H

/* The st_mode entry contains a set of flags describing the file. */
#define S_IFMT		0160000		/* type of file: */
#define S_IFDIR		0040000		/* directory */
#define S_IFCHR		0020000		/* character special */
#define S_IFBLK		0060000		/* block special */
#define S_IFREG		0010000		/* regular */
/* ... */

#endif 	/* L_TYPES_H */
