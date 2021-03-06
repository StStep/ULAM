/**                                        -*- mode:C++ -*-
 * NodeBinaryOpEqualBitwiseOr.h - Node for handling Bitwise
 *                                Or Equal Operation for ULAM
 *
 * Copyright (C) 2014-2016 The Regents of the University of New Mexico.
 * Copyright (C) 2014-2016 Ackleyshack LLC.
 *
 * This file is part of the ULAM programming language compilation system.
 *
 * The ULAM programming language compilation system is free software:
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * The ULAM programming language compilation system is distributed in
 * the hope that it will be useful, but WITHOUT ANY WARRANTY; without
 * even the implied warranty of MERCHANTABILITY or FITNESS FOR A
 * PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the ULAM programming language compilation system
 * software.  If not, see <http://www.gnu.org/licenses/>.
 *
 * @license GPL-3.0+ <http://spdx.org/licenses/GPL-3.0+>
 */

/**
  \file NodeBinaryOpEqualBitwiseOr.h - Node for handling Bitwise Or Equal for ULAM
  \author Elenas S. Ackley.
  \author David H. Ackley.
  \date (C) 2014-2016 All rights reserved.
  \gpl
*/

#ifndef NODEBINARYOPBITWISEOREQUAL_H
#define NODEBINARYOPBITWISEOREQUAL_H

#include "NodeBinaryOpEqualBitwise.h"

namespace MFM{

  class NodeBinaryOpEqualBitwiseOr : public NodeBinaryOpEqualBitwise
  {
  public:

    NodeBinaryOpEqualBitwiseOr(Node * left, Node * right, CompilerState & state);
    NodeBinaryOpEqualBitwiseOr(const NodeBinaryOpEqualBitwiseOr& ref);
    virtual ~NodeBinaryOpEqualBitwiseOr();

    virtual Node * instantiate();


    virtual const char * getName();

    virtual const std::string prettyNodeName();

    virtual const std::string methodNameForCodeGen();

  protected:

    virtual UlamValue makeImmediateBinaryOp(UTI type, u32 ldata, u32 rdata, u32 len);
    virtual UlamValue makeImmediateLongBinaryOp(UTI type, u64 ldata, u64 rdata, u32 len);
    virtual void appendBinaryOp(UlamValue& refUV, u32 ldata, u32 rdata, u32 pos, u32 len);

  };

}

#endif //end NODEBINARYOPBITWISEOREQUAL_H
