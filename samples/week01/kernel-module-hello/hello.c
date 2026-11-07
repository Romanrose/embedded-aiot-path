#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/moduleparam.h>

static char *name = (char *)"world";
module_param(name, charp, 0444);
MODULE_PARM_DESC(name, "Greet target");

static int __init hello_init(void)
{
	pr_info("hello: init, hello %s\n", name);
	return 0;
}

static void __exit hello_exit(void)
{
	pr_info("hello: exit, goodbye %s\n", name);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("embedded-aiot-path");
MODULE_DESCRIPTION("Minimal hello kernel module with a string parameter");

module_init(hello_init);
module_exit(hello_exit);

