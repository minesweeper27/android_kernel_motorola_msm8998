/* Copyright (c) 2015-2016, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _LINUX_MSM_DMA_IOMMU_MAPPING_H
#define _LINUX_MSM_DMA_IOMMU_MAPPING_H

#include <linux/device.h>
#include <linux/dma-buf.h>
#include <linux/scatterlist.h>
#include <linux/dma-mapping.h>

<<<<<<< HEAD
struct msm_iommu_data {
	struct list_head map_list;
	struct mutex lock;
};

=======
>>>>>>> e02b951fa22e3828a842b09f6f65a1d9e971c37d
#ifdef CONFIG_IOMMU_API
/*
* This function is not taking a reference to the dma_buf here. It is expected
* that clients hold reference to the dma_buf until they are done with mapping
* and unmapping.
*/
int msm_dma_map_sg_attrs(struct device *dev, struct scatterlist *sg, int nents,
<<<<<<< HEAD
		   enum dma_data_direction dir, struct dma_buf *dmabuf,
=======
		   enum dma_data_direction dir, struct dma_buf *dma_buf,
>>>>>>> e02b951fa22e3828a842b09f6f65a1d9e971c37d
		   struct dma_attrs *attrs);

static inline int msm_dma_map_sg_lazy(struct device *dev,
			       struct scatterlist *sg, int nents,
			       enum dma_data_direction dir,
<<<<<<< HEAD
			       struct dma_buf *dmabuf)
{
	return msm_dma_map_sg_attrs(dev, sg, nents, dir, dmabuf, NULL);
=======
			       struct dma_buf *dma_buf)
{
	return msm_dma_map_sg_attrs(dev, sg, nents, dir, dma_buf, NULL);
>>>>>>> e02b951fa22e3828a842b09f6f65a1d9e971c37d
}

static inline int msm_dma_map_sg(struct device *dev, struct scatterlist *sg,
				  int nents, enum dma_data_direction dir,
<<<<<<< HEAD
				  struct dma_buf *dmabuf)
=======
				  struct dma_buf *dma_buf)
>>>>>>> e02b951fa22e3828a842b09f6f65a1d9e971c37d
{
	DEFINE_DMA_ATTRS(attrs);

	init_dma_attrs(&attrs);
	dma_set_attr(DMA_ATTR_NO_DELAYED_UNMAP, &attrs);
<<<<<<< HEAD
	return msm_dma_map_sg_attrs(dev, sg, nents, dir, dmabuf, &attrs);
}

void msm_dma_unmap_sg(struct device *dev, struct scatterlist *sg, int nents,
		      enum dma_data_direction dir, struct dma_buf *dmabuf);

void msm_dma_unmap_all_for_dev(struct device *dev);
=======
	return msm_dma_map_sg_attrs(dev, sg, nents, dir, dma_buf, &attrs);
}

void msm_dma_unmap_sg(struct device *dev, struct scatterlist *sgl, int nents,
		      enum dma_data_direction dir, struct dma_buf *dma_buf);

int msm_dma_unmap_all_for_dev(struct device *dev);
>>>>>>> e02b951fa22e3828a842b09f6f65a1d9e971c37d

/*
 * Below is private function only to be called by framework (ION) and not by
 * clients.
 */
<<<<<<< HEAD
void msm_dma_buf_freed(struct msm_iommu_data *data);
=======
void msm_dma_buf_freed(void *buffer);
>>>>>>> e02b951fa22e3828a842b09f6f65a1d9e971c37d

#else /*CONFIG_IOMMU_API*/

static inline int msm_dma_map_sg_attrs(struct device *dev,
			struct scatterlist *sg, int nents,
			enum dma_data_direction dir, struct dma_buf *dma_buf,
			struct dma_attrs *attr)
{
	return -EINVAL;
}

static inline int msm_dma_map_sg_lazy(struct device *dev,
			       struct scatterlist *sg, int nents,
			       enum dma_data_direction dir,
			       struct dma_buf *dma_buf)
{
	return -EINVAL;
}

static inline int msm_dma_map_sg(struct device *dev, struct scatterlist *sg,
				  int nents, enum dma_data_direction dir,
				  struct dma_buf *dma_buf)
{
	return -EINVAL;
}

static inline void msm_dma_unmap_sg(struct device *dev,
					struct scatterlist *sgl, int nents,
					enum dma_data_direction dir,
					struct dma_buf *dma_buf)
{
}

static inline int msm_dma_unmap_all_for_dev(struct device *dev)
{
	return 0;
}

static inline void msm_dma_buf_freed(void *buffer) {}
#endif /*CONFIG_IOMMU_API*/

#endif
