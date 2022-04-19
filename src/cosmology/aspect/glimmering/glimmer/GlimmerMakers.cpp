#include "GlimmerMakers.h"
#include "illuminable/painter/Painter.h"
#include "illuminable/painter/Canvas.h"

namespace cosmographer {

PainterCommunity *GlimmerMakers::createPainterCommunity(Glimmer *glimmer) {
    auto painterCommunityController = mkup<PainterCommunity>();
    auto painterCommunity = painterCommunityController.get();
    glimmer->constituents.push_back(mv(painterCommunityController));

    auto painterController = mkup<Painter>(painterCommunity);
    painterCommunity->painter = painterController.get();
    glimmer->constituents.push_back(mv(painterController));

    auto canvasController = mkup<Canvas>(glimmer->glimmerSoul);
    painterCommunity->canvas = canvasController.get();
    glimmer->illuminables.push_back(painterCommunity->canvas);
    glimmer->constituents.push_back(mv(canvasController));
    return painterCommunity;
}
}
