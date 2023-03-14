/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode* sum = new PolyNode();
        PolyNode* node = sum;
        while(poly1 && poly2){
            if(poly1->power > poly2->power){
                node->next = new PolyNode(poly1->coefficient, poly1->power);
                poly1 = poly1->next;
                node = node->next;
            }
            else if(poly1->power < poly2->power){
                node->next = new PolyNode(poly2->coefficient, poly2->power);
                poly2 = poly2->next;
                node = node->next;
            }
            else{
                if(poly1->coefficient+poly2->coefficient){
                    node->next = new PolyNode(poly1->coefficient+poly2->coefficient, poly1->power);
                    node = node->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        if(poly1 || poly2)
            node->next = poly1?poly1:poly2;
        
        return sum->next;
    }
};