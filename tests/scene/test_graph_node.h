/**************************************************************************/
/*  test_graph_node.h                                                     */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#ifndef TEST_GRAPH_NODE_H
#define TEST_GRAPH_NODE_H

#include "scene/gui/graph_node.h"

#include "tests/test_macros.h"

namespace TestGraphNode {

class TestGraphNode : public GraphNode {
  GDCLASS(TestGraphNode, GraphNode);
};

TEST_CASE("[SceneTree][GraphNode] Testing Graph node deletion of only child") {

  GraphNode *graph_node = memnew(GraphNode);
  Node *node = memnew(Node);

  // Check initial SceneTree setup.
  CHECK_EQ(SceneTree::get_singleton()->get_root()->get_child_count(), 0);

  // Check initial nodes setup.
  CHECK_EQ(graph_node->get_child_count(false), 0);
  CHECK_EQ(node->get_child_count(), 0);

  // Add graph_node to SceneTree.
  SceneTree::get_singleton()->get_root()->add_child(graph_node);

  // Add child to graph_node.
  graph_node->add_child(node);

  // Check graph_node after adding child.
  CHECK_EQ(graph_node->get_child_count(false), 1);

  // Remove child.
  graph_node->remove_child(node);

  // Check graph_node after removing child.
  CHECK_EQ(graph_node->get_child_count(false), 0);

  memdelete(graph_node);
  memdelete(node);
}

} // namespace TestGraphNode

#endif // TEST_GRAPH_NODE_H
