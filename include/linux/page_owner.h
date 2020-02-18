#ifndef __LINUX_PAGE_OWNER_H
#define __LINUX_PAGE_OWNER_H

#include <linux/jump_label.h>

#ifdef CONFIG_PAGE_OWNER
extern struct static_key_false page_owner_inited;
extern struct page_ext_operations page_owner_ops;

extern void __reset_page_owner(struct page *page, unsigned int order);
extern void __set_page_owner(struct page *page,
			unsigned int order, gfp_t gfp_mask);
<<<<<<< HEAD
extern void __split_page_owner(struct page *page, unsigned int order);
extern void __copy_page_owner(struct page *oldpage, struct page *newpage);
extern void __set_page_owner_migrate_reason(struct page *page, int reason);
extern void __dump_page_owner(struct page *page);
=======
extern gfp_t __get_page_owner_gfp(struct page *page);
>>>>>>> b67a656dc4bbb15e253c12fe55ba80d423c43f22

static inline void reset_page_owner(struct page *page, unsigned int order)
{
	if (static_branch_unlikely(&page_owner_inited))
		__reset_page_owner(page, order);
}

static inline void set_page_owner(struct page *page,
			unsigned int order, gfp_t gfp_mask)
{
	if (static_branch_unlikely(&page_owner_inited))
		__set_page_owner(page, order, gfp_mask);
}

static inline void split_page_owner(struct page *page, unsigned int order)
{
	if (static_branch_unlikely(&page_owner_inited))
		__split_page_owner(page, order);
}
static inline void copy_page_owner(struct page *oldpage, struct page *newpage)
{
	if (static_branch_unlikely(&page_owner_inited))
		__copy_page_owner(oldpage, newpage);
}
static inline void set_page_owner_migrate_reason(struct page *page, int reason)
{
	if (static_branch_unlikely(&page_owner_inited))
		__set_page_owner_migrate_reason(page, reason);
}
static inline void dump_page_owner(struct page *page)
{
	if (static_branch_unlikely(&page_owner_inited))
		__dump_page_owner(page);
}

static inline gfp_t get_page_owner_gfp(struct page *page)
{
	if (likely(!page_owner_inited))
		return 0;

	return __get_page_owner_gfp(page);
}
#else
static inline void reset_page_owner(struct page *page, unsigned int order)
{
}
static inline void set_page_owner(struct page *page,
			unsigned int order, gfp_t gfp_mask)
{
}
<<<<<<< HEAD
static inline void split_page_owner(struct page *page,
			unsigned int order)
{
}
static inline void copy_page_owner(struct page *oldpage, struct page *newpage)
{
}
static inline void set_page_owner_migrate_reason(struct page *page, int reason)
{
}
static inline void dump_page_owner(struct page *page)
{
}
=======
static inline gfp_t get_page_owner_gfp(struct page *page)
{
	return 0;
}

>>>>>>> b67a656dc4bbb15e253c12fe55ba80d423c43f22
#endif /* CONFIG_PAGE_OWNER */
#endif /* __LINUX_PAGE_OWNER_H */
