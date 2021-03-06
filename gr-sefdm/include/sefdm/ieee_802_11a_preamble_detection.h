/* -*- c++ -*- */
/* 
 * Copyright 2018 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */


#ifndef INCLUDED_SEFDM_IEEE_802_11A_PREAMBLE_DETECTION_H
#define INCLUDED_SEFDM_IEEE_802_11A_PREAMBLE_DETECTION_H

#include <sefdm/api.h>
#include <gnuradio/block.h>

namespace gr {
  namespace sefdm {

    /*!
     * \brief <+description of block+>
     * \ingroup sefdm
     *
     */
    class SEFDM_API ieee_802_11a_preamble_detection : virtual public gr::block
    {
     public:
      typedef boost::shared_ptr<ieee_802_11a_preamble_detection> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of sefdm::ieee_802_11a_preamble_detection.
       *
       * To avoid accidental use of raw pointers, sefdm::ieee_802_11a_preamble_detection's
       * constructor is in a private implementation
       * class. sefdm::ieee_802_11a_preamble_detection::make is the public interface for
       * creating new instances.
       */
      static sptr make(int summation_window,
                       int signal_offset,
                       float detection_threshold,
                       int detect_thr_cntr_max_val,
//                       bool use_recursive_algorithm,
                       float eps,
                       const std::string& tag_key,  // Имя тэга, будет использовать последующими блоками
                       int packet_len, // Длина пакета
                       int margin); // Запас по длине пакета (чтобы пакет точно вышёл, т.к. детектор сработает до
                                    // до начала пакета) --> используется при формировании packet_len_with_margin
    };

  } // namespace sefdm
} // namespace gr

#endif /* INCLUDED_SEFDM_IEEE_802_11A_PREAMBLE_DETECTION_H */

