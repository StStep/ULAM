/**                                        -*- mode:C++ -*-
 * NodeBinaryOpEqualBitwiseAnd.h - Node for handling Bitwise
 *                                 And Equal Operation for ULAM
 *
 * Copyright (C) 2014-2015 The Regents of the University of New Mexico.
 * Copyright (C) 2014-2015 Ackleyshack LLC.
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
  \file NodeBinaryOpEqualBitwiseAnd.h - Node for handling Bitwise And Equal for ULAM
  \author Elenas S. Ackley.
  \author David H. Ackley.
  \date (C) 2014-2015 All rights reserved.
  \gpl
*/


#ifndef NODEBINARYOPEQUALBITWISEAND_H
#define NODEBINARYOPEQUALBITWISEAND_H

#include "NodeBinaryOpEqualBitwise.h"

namespace MFM{

  class NodeBinaryOpEqualBitwiseAnd : public NodeBinaryOpEqualBitwise
  {
  public:

    NodeBinaryOpEqualBitwiseAnd(Node * left, Node * right, CompilerState & state);
    NodeBinaryOpEqualBitwiseAnd(const NodeBinaryOpEqualBitwiseAnd& ref);
    virtual ~NodeBinaryOpEqualBitwiseAnd();

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

#endif //end NODEBINARYOPEQUALBITWISEAND_H