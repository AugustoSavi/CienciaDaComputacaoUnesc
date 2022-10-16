import { Router } from "express";

import {
    listHeroesController,
    createHeroController,
    findOneHeroesController,
    updateHeroController,
    deleteHeroController
} from "../controllers/index.js";

const heroesRoutes = Router();

heroesRoutes.post("/", (request, response) => {
    return createHeroController().handle(request, response);
});

heroesRoutes.get("/", (request, response) => {
    return listHeroesController().handle(request, response);
});

heroesRoutes.get("/:id", (request, response) => {
    return findOneHeroesController().handle(request, response);
});

heroesRoutes.put("/:id", (request, response) => {
    return updateHeroController().handle(request, response);
});

heroesRoutes.delete("/:id", (request, response) => {
    return deleteHeroController().handle(request, response);
});


export { heroesRoutes };