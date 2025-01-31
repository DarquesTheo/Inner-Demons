/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** vector
*/

#ifndef VECTOR_H_
    #define VECTOR_H_
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Export.h>

//vectors
sfVector2f add_vectors(sfVector2f vec1, sfVector2f vec2);
sfVector2f get_vector_difference(sfVector2f pos1, sfVector2f pos2);
sfVector2f mult_vector(sfVector2f vec, float fac);
sfVector2f normalize_vector(sfVector2f vec);
sfVector2f mult_vectors(sfVector2f vec1, sfVector2f vec2);
void print_vectorf(sfVector2f vec);
void print_vectori(sfVector2i vec);

#endif /* !VECTOR_H_ */
