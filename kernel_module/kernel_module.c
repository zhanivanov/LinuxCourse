#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>

// Information about the kernel module
MODULE_AUTHOR("Zhan Ivanov");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("This is just a simple kernel module.");

// Pass this argument when initializing the module(ex. insmod *kernel_name* mystring=test
char *mystring;
module_param(mystring, charp, 0);

// Information about the kernel module parameters
MODULE_PARM_DESC(mystring, "A character string");

// Prints a message in /proc/*filename*
static int simple_module_message(struct seq_file *m, void *v) {
  seq_printf(m, "%s\n", mystring);
  return 0;
}

// Opens a file in /proc
static int simple_module_open(struct inode *inode, struct  file *file) {
  return single_open(file, simple_module_message, NULL);
}

static const struct file_operations simple_module_fops = {
  .owner = THIS_MODULE,
  .open = simple_module_open,
  .read = seq_read,
  .llseek = seq_lseek,
  .release = single_release,
};

// Kernel module initializing function
static int __init simple_module_init(void) {
  proc_create("justASimpleModule", 0, NULL, &simple_module_fops);
  return 0;
}

// This function is called when the module is stopped
static void __exit simple_module_exit(void) {
	printk(KERN_ALERT "Exit from simple module.\n");
	remove_proc_entry("justASimpleModule", NULL);
}

module_init(simple_module_init);
module_exit(simple_module_exit);

