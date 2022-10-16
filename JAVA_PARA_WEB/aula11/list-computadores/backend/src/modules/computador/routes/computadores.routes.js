import { Router } from "express";

import {
    listComputadoresController,
    createComputadorController,
    findOneComputadorController,
    updateComputadorController,
    deleteComputadorController
} from "../controllers/index.js";

const computadoresRoutes = Router();

computadoresRoutes.post("/", (request, response) => {
    return createComputadorController().handle(request, response);
});

computadoresRoutes.get("/", (request, response) => {
    return listComputadoresController().handle(request, response);
});

computadoresRoutes.get("/:id", (request, response) => {
    return findOneComputadorController().handle(request, response);
});

computadoresRoutes.put("/:id", (request, response) => {
    return updateComputadorController().handle(request, response);
});

computadoresRoutes.delete("/:id", (request, response) => {
    return deleteComputadorController().handle(request, response);
});


export { computadoresRoutes };