/**
 * $Id$
 *
 * ***** BEGIN GPL/BL DUAL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. The Blender
 * Foundation also sells licenses for use in proprietary software under
 * the Blender License.  See http://www.blender.org/BL/ for information
 * about this.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL/BL DUAL LICENSE BLOCK *****
 */
#include "KX_MotionState.h"
#include "SG_Spatial.h"

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

KX_MotionState::KX_MotionState(SG_Spatial* node) : m_node(node)
{

}

KX_MotionState::~KX_MotionState()
{
}

void	KX_MotionState::getWorldPosition(float& posX,float& posY,float& posZ)
{
	MT_Point3 pos = m_node->GetWorldPosition();
	posX = pos[0];
	posY = pos[1];
	posZ = pos[2];
}

void	KX_MotionState::getWorldScaling(float& scaleX,float& scaleY,float& scaleZ)
{
	MT_Vector3 scale = m_node->GetWorldScaling();
	scaleX = scale[0];
	scaleY = scale[1];
	scaleZ = scale[2];
}

void	KX_MotionState::getWorldOrientation(float& quatIma0,float& quatIma1,float& quatIma2,float& quatReal)
{
	MT_Quaternion orn = m_node->GetWorldOrientation().getRotation();
	quatIma0 = orn[0];
	quatIma1 = orn[1];
	quatIma2 = orn[2];
	quatReal = orn[3];
}
	
void	KX_MotionState::setWorldPosition(float posX,float posY,float posZ)
{
	m_node->SetLocalPosition(MT_Point3(posX,posY,posZ));

}

void	KX_MotionState::setWorldOrientation(float quatIma0,float quatIma1,float quatIma2,float quatReal)
{
	MT_Quaternion orn;
	orn[0] = quatIma0;
	orn[1] = quatIma1;
	orn[2] = quatIma2;
	orn[3] = quatReal;

	m_node->SetLocalOrientation(orn);
}

void	KX_MotionState::calculateWorldTransformations()
{
	m_node->ComputeWorldTransforms(NULL);
}

 
