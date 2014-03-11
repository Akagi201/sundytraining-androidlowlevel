#include <stdio.h>
#include <malloc.h>

typedef int (*MYOPEN)(char *filename, int flag);

struct myfile_ops
{
	MYOPEN open;
};

struct demodev
{
	int devnum;
	struct myfile_ops *fops;
};

struct myfile
{
	int flag;
	int pos;
	struct myfile_ops *fops;
};

struct demodev *arr_inode[2];
struct myfile  *arr_file[2];

int register_demo(struct demodev *pdev, struct myfile_ops *fops, int devnum)
{
	pdev->devnum=devnum;
	pdev->fops=fops;

	arr_inode[0] = pdev;

	printf(" register_demo ---\r\n");

	return 0;
}

int mysys_open(char *filename, int flag)
{
	//读取设备文件中的主次设备号
	//查找设备节点
	
	//
	printf(" mysys_open ---0\r\n");

	struct myfile *file = malloc(sizeof(struct myfile));
	arr_file[0] = file;

	arr_file[0]->flag = flag;
	arr_file[0]->fops = arr_inode[0]->fops;

	printf(" mysys_open ---1\r\n");

	arr_file[0]->fops->open(filename, flag);

	printf(" mysys_open ---2\r\n");

	return 0;
}

/*-------------------------------------------------*/

int drvopen(char *filename, int flag)
{
	printf("file: %s-%d\r\n", filename, flag);
	return 0;
}

struct myfile_ops ops ={ \
	.open = drvopen, \
};

struct demodev cdev;

/*初始化模块*/
int init_fun(void)
{
	printf("init_fun ---\r\n");
	return register_demo(&cdev, &ops, 100);
}
/*-------------------------------------------------*/

int myopen(char *filename, int flag)
{
	return mysys_open(filename, flag);
}

int main(int argv, char **argc)
{
	init_fun();

	//---------------

	myopen("demo", 123);

	return 0;
}


