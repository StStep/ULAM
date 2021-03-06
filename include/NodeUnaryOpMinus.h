/**                                        -*- mode:C++ -*-
 * NodeUnaryOpMinus.h -  Node handling Unary Minus Operator for ULAM
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
  \file NodeUnaryOpMinus.h -  Node handling Unary Minus Operator for ULAM
  \author Elenas S. Ackley.
  \author David H. Ackley.
  \date (C) 2014-2016   All rights reserved.
  \gpl
*/


#ifndef NODEUNARYOPMINUS_H
#define NODEUNARYOPMINUS_H

#include "NodeUnaryOp.h"

namespace MFM{

  class NodeUnaryOpMinus : public NodeUnaryOp
  {
  public:

    NodeUnaryOpMinus(Node * n, CompilerState & state);

    NodeUnaryOpMinus(const NodeUnaryOpMinus& ref);

    virtual ~NodeUnaryOpMinus();

    virtual Node * instantiate();

    virtual const char * getName();

    virtual const std::string prettyNodeName();

    virtual const std::string methodNameForCodeGen();

  protected:
    virtual UTI calcNodeType(UTI uti);

    virtual UlamValue makeImmediateUnaryOp(UTI type, u32 data, u32 len);
    virtual UlamValue makeImmediateLongUnaryOp(UTI type, u64 data, u32 len);

  private:

  };

} //MFM

#endif //NODEUNARYOPMINUS_H
