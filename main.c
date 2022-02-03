#include <9/9.h>

#include <pwd.h>

char *argv0;

void
usage(void)
{
	fprint(2, "usage: %s [uid]\n", argv0);
	exit(1);
}

int
main(int argc, char *argv[])
{
	struct passwd *pw;
	int uid;

	argv0 = argv[0] ;
	switch(argc){
	case 1 :
		uid = getuid() ;
		break;
	case 2 :
		uid = atoi(argv[1]) ;
		break;
	default:
		usage();
	}

	pw = getpwuid(uid) ;
	if(!pw){
		fprint(2, "%s: getpwuid: cannot find user for %d UID\n", argv0, uid);
		exit(1);
	}

	print("%s", pw->pw_name);

	return 0 ;
}
