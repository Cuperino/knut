/*
  This file is part of Knut.

  SPDX-FileCopyrightText: 2024 Klarälvdalens Datakonsult AB, a KDAB Group company <info@kdab.com>

  SPDX-License-Identifier: GPL-3.0-only

  Contact KDAB at <info@kdab.com> for commercial licensing options.
*/

#pragma once

#include "node.h"

struct TSTree;

namespace treesitter {

class Parser;

class Tree
{
public:
    Tree(const Tree &) = delete;
    Tree(Tree &&) noexcept;

    Tree &operator=(const Tree &) = delete;
    Tree &operator=(Tree &&) noexcept;

    ~Tree();

    Node rootNode() const;

    void swap(Tree &other) noexcept;

private:
    Tree(TSTree *tree);

    TSTree *m_tree;

    friend class Parser;

    // TODO: Once update is implemented, store weak pointers to all
    // TSNodes so that they may be updated as well.
};

}
