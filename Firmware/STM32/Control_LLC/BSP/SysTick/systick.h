/*
 * systick.h
 *
 *  Created on: Jul 9, 2024
 *      Author: dongkhoa
 */

#ifndef SYSTICK_SYSTICK_H_
#define SYSTICK_SYSTICK_H_

#ifdef __cplusplus
extern "C"
{
#endif

  /**********************
   *   PUBLIC FUNCTIONS
   **********************/
  void systick_timer_start(void);
  void systick_timer_stop(void);
  void systick_timer_init(void);

#ifdef __cplusplus
}
#endif

#endif /* SYSTICK_SYSTICK_H_ */
