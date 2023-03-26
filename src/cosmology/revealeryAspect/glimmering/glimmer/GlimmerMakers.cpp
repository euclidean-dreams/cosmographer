#include "GlimmerMakers.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/Painter.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/Canvas.h"
#include "cosmology/revealeryaspect/glimmering/glimmer/illuminable/painter/SingleColorCanvas.h"

namespace cosmographer {

PainterCommunity *GlimmerMakers::createPainterCommunity(
        Glimmer *glimmer,
        bool singleColorCanvas
) {
    auto painterCommunityController = mkup<PainterCommunity>();
    auto painterCommunity = painterCommunityController.get();
    glimmer->constituents.push_back(mv(painterCommunityController));

    auto painterController = mkup<Painter>(painterCommunity);
    painterCommunity->painter = painterController.get();
    glimmer->constituents.push_back(mv(painterController));

    up<Canvas> canvasController;
    if (singleColorCanvas) {
        canvasController = mkup<SingleColorCanvas>(glimmer->glimmerSoul);
    } else {
        canvasController = mkup<Canvas>(glimmer->glimmerSoul);
    }
    painterCommunity->canvas = canvasController.get();
    glimmer->illuminables.push_back(painterCommunity->canvas);
    glimmer->constituents.push_back(mv(canvasController));
    return painterCommunity;
}

}
