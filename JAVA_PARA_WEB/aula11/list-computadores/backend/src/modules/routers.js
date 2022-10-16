import { Router } from "express";

import { computadoresRoutes } from "./computador/routes/computadores.routes.js";

const router = Router();

router.use("/computador", computadoresRoutes);

export { router };
