/*
 *
 * Copyright 2021-2024 Software Radio Systems Limited
 *
 * This file is part of srsRAN.
 *
 * srsRAN is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsRAN is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#pragma once

#include "srsran/adt/span.h"
#include "srsran/phy/upper/channel_coding/polar/polar_code.h"
#include <cstdint>

namespace srsran {

class polar_rate_matcher
{
public:
  virtual ~polar_rate_matcher() = default;

  /*!
   * Carries out the actual rate-matching.
   * \param[in] input        The codeword obtained from the polar encoder.
   * \param[out] output      The rate-matched codeword resulting from the rate-matching
   *                         operation.
   * \param[in] n            \f$log_2\f$ of the codeword length.
   * \param[in] E            Rate-matched codeword length.
   * \param[in] K            Message size (including CRC).
   * \return An integer: 0 if the function executes correctly, -1 otherwise.
   */
  virtual void rate_match(span<uint8_t> output, span<const uint8_t> input, const polar_code& code) = 0;
};

} // namespace srsran