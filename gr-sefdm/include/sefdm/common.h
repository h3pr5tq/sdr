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


#ifndef INCLUDED_SEFDM_COMMON_H
#define INCLUDED_SEFDM_COMMON_H

#include <sefdm/api.h>

namespace gr {
  namespace sefdm {

    void
    get_inf_subcarrier_number(int sym_sefdm_len, int sym_right_gi_len, int sym_left_gi_len,
                              // out:
                              int& sym_n_inf_subcarr,
                              int& sym_n_right_inf_subcarr,
                              int& sym_n_left_inf_subcarr);

    int
    get_add_zero_subcarrier_number(int sym_fft_size, int sym_sefdm_len);

    std::vector<std::vector<gr_complex>>
    get_idft_matrix(int n_point, float alfa);

    std::vector<std::vector<gr_complex>>
    get_c_matrix(int n_point, float alfa);

    std::vector<std::vector<gr_complex>>
    get_eye_c_matrix(int n_point, float alfa);

    /*!
     * \brief <+description+>
     *
     */
    class SEFDM_API common
    {
    public:
      common();
      ~common();
    private:
    };

  } // namespace sefdm
} // namespace gr

#endif /* INCLUDED_SEFDM_COMMON_H */

