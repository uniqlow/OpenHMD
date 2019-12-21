/*
 * Pose estimation using OpenCV
 * Copyright 2015 Philipp Zabel
 * SPDX-License-Identifier:	LGPL-2.0+ or BSL-1.0
 */
#ifndef __OPENCV_H__
#define __OPENCV_H__

#include "rift.h"
#include "rift-sensor-maths.h"
#include "debug-common.h"

#if HAVE_OPENCV
bool estimate_initial_pose(struct blob *blobs, int num_blobs,
			   rift_led *leds, int num_leds,
			   dmat3 *camera_matrix, double dist_coeffs[4],
			   quatf *rot, vec3f *trans, int *num_leds_out,
			   bool use_extrinsic_guess,
         DebugVisCallback debug_cb, void *cb_data);

void rift_project_points(rift_led *leds, int num_led_pos,
  dmat3 *camera_matrix, double dist_coeffs[4],
  quatf *rot, vec3f *trans,
  vec3f *out_points);
#else
static inline
bool estimate_initial_pose(struct blob *blobs, int num_blobs,
			   rift_led *leds, int num_leds,
			   dmat3 *camera_matrix, double dist_coeffs[4],
			   quatf *rot, vec3f *trans, int *num_leds_out,
			   bool use_extrinsic_guess,
         DebugVisCallback debug_cb, void *cb_data);
{
	(void)blobs;
	(void)num_blobs;
	(void)leds;
	(void)num_leds;
	(void)camera_matrix;
	(void)dist_coeffs;
	(void)rot;
	(void)trans;
	(void)num_leds_out;
	(void)use_extrinsic_guess;
	(void)debug_cb;
	(void)cb_data;
  return false;
}
#define rift_project_points(leds,num_led_pos,camera_matrix,dist_coeffs,rot,trans,out_points)
#endif /* HAVE_OPENCV */

#endif /* __OPENCV_H__ */
