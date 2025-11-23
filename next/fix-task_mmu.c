From 8a0a7bc0c813262206ba1c95483ceff4acb19607 Mon Sep 17 00:00:00 2001
From: kylieeXD <khayloaftck@gmail.com>
Date: Sun, 23 Nov 2025 10:59:40 +0000
Subject: [PATCH] kernel: fix task_mmu.c

Change-Id: I5dd31285128cd878230369a3a30a91e725da3141
---
 fs/proc/task_mmu.c | 4 ++++
 1 file changed, 4 insertions(+)

diff --git a/fs/proc/task_mmu.c b/fs/proc/task_mmu.c
index bf966767d..cf26819c8 100644
--- a/fs/proc/task_mmu.c
+++ b/fs/proc/task_mmu.c
@@ -1764,6 +1764,10 @@ static ssize_t pagemap_read(struct file *file, char __user *buf,
 	unsigned long end_vaddr;
 	int ret = 0, copied = 0;
 
+#ifdef CONFIG_KSU_SUSFS_SUS_MAP
+       struct vm_area_struct *vma;
+#endif
+
 	if (!mm || !mmget_not_zero(mm))
 		goto out;
 
-- 
2.43.0
  
