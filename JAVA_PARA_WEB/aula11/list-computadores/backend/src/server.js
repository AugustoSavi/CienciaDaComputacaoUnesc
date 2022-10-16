import 'express-async-errors';
import express from "express";
import cors from "cors"
import { router } from './modules/routers.js';
import AppError from "./shared/errors/AppError.js";

const app = express();
const PORT = 5000;

import "./database/index.js";

app.use(express.json());
app.use(cors());
app.use(router);

app.use((error, request, response, next) => {
    if (error instanceof AppError) {
        return response.status(error.statusCode).json({
            status: 'error',
            message: error.message
        })
    }
    console.log(error)
    return response.status(500).json({
        status: 'error',
        message: 'Internal server error'
    })
})

app.listen(PORT, () => console.log(`server started: http://localhost:${PORT}`));