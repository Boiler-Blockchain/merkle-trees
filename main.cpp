/**
 * @file main.cpp
 *
 * Boiler Blockchain Project - Merkle Tree Implementation
 *
 * This code is part of a Merkle Tree implementation for Boiler Blockchain's
 * Web3 course. It is intended to demonstrate the concepts of hashing,
 * tree structures, and data integrity in blockchain contexts.
 *
 * Author: Soham Jog
 * Organization: Boiler Blockchain, Purdue University
 *
 * Description:
 * This implementation uses C++'s standard library hash functions to construct
 * a simplified Merkle Tree, demonstrating the fundamental structure without
 * relying on external cryptographic libraries.
 *
 *
 * © Boiler Blockchain - All Rights Reserved
 */

#include <iostream>
#include <string>
#include <vector>
#include <functional> // For std::hash

using namespace std;

/*
 * Node structure for Merkel Tree
 */
struct MerkleNode
{
  string hash;        // Store the hash value
  MerkleNode *left;   // Left child
  MerkleNode *right;  // Right child
  MerkleNode *parent; // Parent node is needed so that we can generate merkl proofs
  MerkleNode(string h) : hash(h), left(nullptr), right(nullptr), parent(nullptr) {}
};

// For debugging purposes
void displayTree(MerkleNode *node, int level = 0)
{
  if (node == nullptr)
    return;

  // Indent
  for (int i = 0; i < level; ++i)
  {
    cout << "    ";
  }

  // Print the current node's hash value
  cout << "|-- " << node->hash << endl;

  // Recursively print left and right children at the next level
  if (node->left || node->right)
  {
    displayTree(node->left, level + 1);
    displayTree(node->right, level + 1);
  }
}

/*
 * Note that usually Merkle trees use more cryptographically
 * secure hash functions like sha256
 */
string simple_hash(string data)
{
  // Using std::hash to generate a hash
  hash<string> hasher;
  return to_string(hasher(data));
}

// Combine two hashes to make a parent node
string combine_hashes(const string left_hash, const string right_hash)
{
  return to_string(hash<string>{}(left_hash + right_hash));
}

// Build a Merkle Tree Recursively
MerkleNode *build_merkle_tree(vector<string> data_blocks)
{
  /*
   * Step 1: Adjust the data blocks vector to have a size 2^k. Pad with "_"s at the end if needed.
   */

  /*
   * Step 2: Build the tree.
   * You can use any method that you would like. I would recommend building the tree "bottom-up". Here is
   * some starter code for that approach.
   */
  vector<MerkleNode *> nodes;
  for (int i = 0; i < data_blocks.size(); i++)
  {
    // make a leaf node for each data block
    nodes.push_back(new MerkleNode(simple_hash(data_blocks[i])));
  }
  while (nodes.size() > 1)
  {
    /*
     * 1. Combine hashes for the first 2 elements. Pop the first 2 elements from the nodes array.
     * 2. Make a merklenode with the hashes.
     * 3. Append at the end of the nodes array.
     *
     */
  }
  // Yay
  return nodes[0];
}

/*
 * Merkle proofs are needed to verify if a certain node is in the merkle tree
 * This is very useful in verifying if an element belongs to a pre-determined set in O(logn)
 * Example: Airdropping tokens to addresses
 * 
 * Note that we have a string and a bool for each element of the proof
 * The string is the sibling hash, and the bool is to keep a track of whether the sibling is the left or the right sibling.
 * This will be useful when you verify a leaf hash
 */
vector<pair<string, bool>>  generate_merkle_proof(MerkleNode *root, MerkleNode *leaf)
{
  vector<pair<string, bool>>  proof;
  /*
   * 1. Traverse from leaf to root
   * 2. In the process, get the sibling's hash of each node and push it in the proof.
   */
  return proof;
}

/*
 * Merkle verification in O(logn time)
 */
bool verify(MerkleNode *root, MerkleNode *leaf, vector<pair<string, bool>> merkle_proof)
{
  /*
  * 1. Traverse from leaf to root
  * 2. Verify that sibling hash matches the merkle proof at the right index
  */
 // Returning true if no discrepancy found
  return true;
}

int main()
{
  // Example you can play around with
  vector<string> data_blocks = {"Soham is goated", "Adithya is kinda lame", "another example data block", "boom"};
  /*
   * MerkleNode* root = build_merkle_tree(data_blocks);
   */
}