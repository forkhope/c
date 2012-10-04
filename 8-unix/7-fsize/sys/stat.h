#ifndef L_STAT_H
#define L_STAT_H

#include <sys/types.h>	/* for dev_t, ino_t, etc.*/
#include <time.h>		/* for time_t */

struct stat 	/* inode information returned by stat() */
{
	dev_t		st_dev;		/* device of inode */
	ino_t		st_ino;		/* inode number */
	short		st_mode;	/* mode bits */
	short		st_nlink;	/* number of links */
	short		st_uid;		/* owners user id */
	short		st_gid;		/* owners group id */
	dev_t		st_rdev;	/* for special files */
	off_t		st_size;	/* file size in characters */
	time_t		st_atime;	/* time last accessed */
	time_t		st_mtime;	/* time last modified */
	time_t		st_ctime;	/* time originally created */
};

#endif	/* L_STAT_H */
