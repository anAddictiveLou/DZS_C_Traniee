#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdv

#define SIZE 512

char device_buffer[SIZE];
dev_t device_number;
struct cdev pcd_cdev;
struct file_operations pcd_fops;

static int __init psd_module_init(void)
{
    return 0;
}

static int __exit psd_module_exit(void)
{
    return 0;
}

module_init(psd_module_init());
module_exit(psd_module_exit);