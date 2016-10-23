//
// Created by boris on 23.10.16.
//

#ifndef LIBELECTRICITY_GRU_FUNCTIONS_H
#define LIBELECTRICITY_GRU_FUNCTIONS_H

template <typename MapType, typename Functor>
void doSmthWithMapValues(std::map<std::string, MapType *> _map, Functor function){
    for (auto&& Item : _map) {
        function(Item.second);
    }
}

#endif //LIBELECTRICITY_GRU_FUNCTIONS_H
